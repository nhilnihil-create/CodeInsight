#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

vector<int> f(int x, vector<int> ary){

}

int main(){
    int odd = 1;
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n){ cin >> a.at(i);}

    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 1){
            odd *= 1;
        }else{
            odd *= 2;
        }
    }

    put(int(pow(3,n) - odd));
}