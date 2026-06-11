#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int n, k; cin>> n >> k;
    string s; cin>> s;
    int a = s[k-1];
    a += 32;
    s[k-1] = a;
    cout<< s << endl;
}
