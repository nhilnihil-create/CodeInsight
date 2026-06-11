#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)

const ll INF = 10010001010;
const int inf = 1000034000;
typedef vector<ll> vecl;
typedef vector<int> veci;
typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int N;
    cin >> N;
    vector<int> D(N);
    vector<bool> used(N,false);
    int itrT = 0;
    int itrD = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
    }
    int M;
    cin >> M;
    vector<int> T(M);
    for (int i = 0; i < M;i++)
    {
        cin >> T[i];
    }
    sort(all(D));
    sort(all(T));
    bool ok = false;
    while(1){
        if(D[itrD] == T[itrT]){
            itrD++;
            itrT++;
        }
        else if(D[itrD] < T[itrT]){
            itrD++;
        }
        else{
            break;
        }
        if(itrT == M){
            ok = true;
            break;
        }
        if(itrD == N){
            break;
        }
    }
    if(ok){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
