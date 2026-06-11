#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()


vector<string> p={"ABC","ARC","AGC"};

int main(){
    int n;; cin>>n;;
    if(n<1200){
        cout<<p[0]<<endl;
        return 0;
    }
    if(n<2800){
        cout<<p[1]<<endl;
        return 0;
    }
    cout<<p[2]<<endl;
    return 0;
}