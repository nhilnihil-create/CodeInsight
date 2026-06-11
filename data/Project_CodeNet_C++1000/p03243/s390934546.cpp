#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll n;
    cin>>n;
    if(n%111==0){
        cout<<n<<endl;
    }else{
        if(n<(n/100*111)){
            cout<<n/100*111<<endl;
        }else{
            cout<<(n/100+1)*111<<endl;
        }
    }

}

