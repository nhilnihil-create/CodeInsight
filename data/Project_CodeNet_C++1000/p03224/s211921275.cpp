#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int aa[1010][1010];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int m=1;
    vector<int> a;
    while((m*(m+1))/2<=100000){
        a.push_back((m*(m+1))/2);
        m++;
    }
    bool f=false;
    int p;
    for(int i=0;i<a.size();i++){
        if(a[i]==n){
            f=true;
            p=i+1;
        }
    }
    int l=p+1;
    if(!f){
        cout<<"No"<<endl;
        return 0;
    }
    else{
        cout<<"Yes"<<endl<<p+1<<endl;
        for(int i=0;i<p;i++)aa[0][i]=i+1;
        for(int i=1;i<=p;i++){
            for(int j=0;j<i;j++)aa[i][j]=aa[j][i-1];
            for(int j=i;j<p;j++)aa[i][j]=l++;
        }
    }
    for(int i=0;i<=p;i++){
        cout<<p<<" ";
        for(int j=0;j<p;j++){
            cout<<aa[i][j]<<" ";
        }
        cout<<endl;
    }

}