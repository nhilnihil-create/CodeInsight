#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    string N; cin>> N;
    int sum = 0;
    rep(i, N.size()){
        sum += N[i] - '0';
    }

    int N2 = (N[0] - '0') + 9 * (N.size() - 1);
    if(sum < N2) N2--;
    cout<< N2 << endl;
}
