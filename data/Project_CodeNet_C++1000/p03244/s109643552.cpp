#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int c = 100005;
    vector<int> odd(c,0), even(c,0);
    for (int i = 0; i < N; i++) {
        if(i % 2 == 0){
            even[v[i]]++;
        }
        else{
            odd[v[i]]++;
        }
    }

    int ea, eb, oa, ob;
    ea = 0; eb = 0; oa = 0; ob = 0;
    int eai, ebi, oai, obi;
    for (int i = 0; i < c; i++) {
        if(even[i] > ea){
            eb = ea;
            ebi = eai;
            ea = even[i];
            eai = i;
        }
        else if(even[i] > eb){
            eb = even[i];
            ebi = i;
        }
        if(odd[i] > oa){
            ob = oa;
            obi = oai;
            oa = odd[i];
            oai = i;
        }
        else if(odd[i] > ob){
            ob = odd[i];
            obi = i;
        }
    }

    if(eai != oai){
        printf("%d\n", N - ea - oa);
    }
    else{
        printf("%d\n", min(N - ea - ob, N - eb - oa));
    }




}