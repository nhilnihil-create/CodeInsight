#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a1(n);
    vector<int> a2(n);
    for(int i=0; i<n; i++){
        cin >> a1[i];
    }
    for(int i=0; i<n; i++){
        cin >> a2[i];
    }
    int tmp=0;
    int mx=0;
    for(int i=0; i<n; i++){
        tmp = 0;
        for(int j=0; j<n; j++){
            if(j>i){
                tmp += a2[j];
            }else if(j==i){
                tmp += a1[j];
                tmp += a2[j];
            }else{
                tmp += a1[j];
            }
            //cout << tmp << " ";
        }
        mx = max(mx,tmp);
       //cout << tmp << endl;
    }
    cout << mx << endl;
}


