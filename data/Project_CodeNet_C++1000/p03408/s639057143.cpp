#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    vector<string> blue(n);
    for(int i=0;i<n;i++){
        cin>>blue[i];
    }
    cin>>m;
    vector<string> red(m);
    for(int i=0;i<m;i++){
        cin>>red[i];
    }
    int max=0;
    vector<int> bcnt(n);
    for(int i=0;i<n;i++){
        if(bcnt[i]==0){
            int tmp=1;
            for(int k=i+1;k<n;k++){
                if(blue[i]==blue[k]){
                    tmp++;
                    bcnt[k]=1;
                }
            }
            for(int k=0;k<m;k++){
                if(blue[i]==red[k]){
                    tmp--;
                }
            }
            if(tmp>max)max=tmp;
        }
    }
    cout<<max<<endl;
    return 0;
}