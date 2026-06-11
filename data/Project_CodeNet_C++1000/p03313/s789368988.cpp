#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

const int M = 1<<18;

int main(){
    int m_idx[M], m2_idx[M];
    m_idx[0] = 0;
    m2_idx[0] = -1;
    int N;
    cin >> N;
    int A[M];
    for(int i = 0; i < (1<<N); i++){
        cin >> A[i];
    }
    for(int i = 1; i < (1<<N); i++){
        m_idx[i] = -1;
        for(int j = 0; j <= N; j++){
            int n = (1<<j);
            if(i&n){
                int m = i-n;
                if(m == 0){
                    if(A[i] > A[0]) {
                        m_idx[i] = i;
                        m2_idx[i] = 0;
                    }else{
                        m_idx[i] = 0;
                        m2_idx[i] = i;
                    }
                }else{
                    if(m_idx[i] == -1){
                        P cnd[3] = {P(A[m_idx[m]], m_idx[m]), P(A[m2_idx[m]], m2_idx[m]), P(A[i], i)};
                        sort(cnd, cnd+3, greater<P>());
                        m_idx[i] = cnd[0].second;
                        m2_idx[i] = cnd[1].second;
                    }else{
                        P cnd[4] = {P(A[m_idx[m]], m_idx[m]), P(A[m2_idx[m]], m2_idx[m]), P(A[m_idx[i]], m_idx[i]), P(A[m2_idx[i]], m2_idx[i])};
                        sort(cnd, cnd+4, greater<P>());
                        m_idx[i] = cnd[0].second;
                        for(int k = 1; k < 4; k++){
                            if(cnd[k].second != cnd[0].second){
                                m2_idx[i] = cnd[k].second;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    int tmp_max = A[0]+A[1];
    cout << tmp_max << '\n';
    for(int i = 2; i < (1<<N); i++){
        //cout << m_idx[i] << ' ' << m2_idx[i] << endl;
        tmp_max = max(tmp_max, A[m_idx[i]]+A[m2_idx[i]]);
        cout << tmp_max << endl;
    }
}