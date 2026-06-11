#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef tuple<int,int,int> T;

int main(){
    int N, C; cin >> N >> C;
    vector<T> program(N);
    rep(i,N){
        int s, t, c; cin >> s >> t >> c;
        program[i] = T(s,t,c);
    }

    sort(program.begin(), program.end());

    vector<T> record;
    record.push_back(program[0]);

    rep1(i,N-1){
        T now = program[i]; bool flag = true;

        rep(j, record.size()){
            if(get<2>(record[j]) == get<2>(now)){
                if(get<1>(record[j]) <= get<0>(now)){
                    record[j] = now;
                    flag = false; break;
                }
            } else {
                if(get<1>(record[j]) < get<0>(now)){
                    record[j] = now;
                    flag = false; break;
                }
            }
        }

        if(flag) record.push_back(now);

        
    }

    cout << record.size() << endl;
}