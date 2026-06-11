#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;


int N, M;
vector<ll> A;
vector<P> Card;
ll a, b, c;
ll res = 0;

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){ cin >> a; A.push_back(a); }
    for(int i = 0; i < M; i++){
        cin >> b >> c;
        Card.push_back({c,b});
    }

    sort(A.begin(), A.end());
    sort(Card.begin(), Card.end());
    reverse(Card.begin(), Card.end());

    int i = 0, j = 0;
    while(i < N && A[i] < Card[j].first){
        int k = 0;
        while(i+k < N && k < Card[j].second && A[i+k] < Card[j].first){
            A[i+k] = Card[j].first;
            ++k;
        }
        i += k;
       ++j;
    }

    for(int i = 0; i < N; i++) res += A[i];
    cout << res << endl;

    return 0;

}