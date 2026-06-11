#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll D[N];
    ll i,j;
    for(i=0;i<N;i++){
        cin >> D[i];
    }
    ll M;
    cin >> M;
    ll T[M];
    for(i=0;i<M;i++){
        cin >> T[i];
    }
    sort(D,D+N);
    sort(T,T+M);
    i=0;j=0;
    while(i<N){
        while(j<M){
            if(i>=N||D[i]>T[j]){
                cout <<"NO";
                return 0;
            }
            if(D[i]<T[j])i++;
            if(D[i]==T[j]){
                j++;
                i++;
            }
        }
        i++;
    }
    cout << "YES";
    return 0;
}
