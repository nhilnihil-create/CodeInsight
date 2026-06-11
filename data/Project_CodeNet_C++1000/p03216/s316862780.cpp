#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

struct counter{ll d; ll m; ll dm;};

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    for(int i=0; i<Q; i++){
        ll ans=0;
        counter cnt={0,0,0};
        int k;
        cin >> k;
        for(int j=0; j<N; j++){
            if(j>=k){
                if(S[j-k]=='D'){
                    cnt.d--;
                    cnt.dm-=cnt.m;
                }else if(S[j-k]=='M'){
                    cnt.m--;
                }
            }

            if(S[j]=='D'){
                cnt.d++;
            }else if(S[j]=='M'){
                cnt.m++;
                cnt.dm+=cnt.d;
            }else if(S[j]=='C'){
                ans+=cnt.dm;
            }
        }

        cout << ans << endl;
    }
}