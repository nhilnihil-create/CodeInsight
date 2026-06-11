#include <bits/stdc++.h>

typedef long long ll;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

const int N = 1e4 + 69;
const ll INF = 1e18;

int n;
ll answer;
ll best[N];
bool  fix[N];

vector < pair <int,int> > P;

struct bla{
        int w, s, v;
};

bla A[N];

bool cmp(bla A, bla B){
        int cnt_A = A.s - B.w;
        int cnt_B = B.s - A.w;
        if(cnt_A == cnt_B){
                return A.s < B.s;
        }
        return cnt_A < cnt_B;
}

int main(){

        ios::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> A[i].w >> A[i].s >> A[i].v;

        }

        sort(A+1, A+1+n, cmp);

        fix[0] = 1;
        cout << endl;
        for(int i = 1; i <= n; i++){
                ll answer_i = 0;
                for(int j = 0; j <= A[i].s; j++){
                        answer_i = max(answer_i, best[j]);
                }


                answer_i += A[i].v;
                answer = max(answer, answer_i);


                for(int j = A[i].s; j >= 0; j--){
                        if(fix[j]){
                                int to = j + A[i].w;
                                if(to > 1e4) continue;
                                best[to] = max(best[to], best[j] + A[i].v);
                                fix[to] = 1;
                        }
                }
        }

        cout << answer << endl;
}
