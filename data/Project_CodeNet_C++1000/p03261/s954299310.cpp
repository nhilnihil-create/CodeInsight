#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<string> w(n);
    map<string,long long> m;
    f(i,0,n){
        cin>>w[i];
        m[w[i]]++;
    }
    bool f=true;
    f(i,0,n-1){
        if(w[i][w[i].size()-1]!=w[i+1][0]){
            f=false;
        }
        else if(m[w[i]]>1){
            f=false;
        }
    }
    if(f){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
