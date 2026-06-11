#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<int> D(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
    }
    
    int M;
    cin >> M;
    vector<int> T(M, 0);
    for(int i = 0; i < M; i++){
        cin >> T[i];
    }
    
    if( M > N){
        cout << "NO" << endl;
        return 0;
    }
    sort(D.begin(), D.end());
    sort(T.begin(), T.end());

    int i_d = 0;
    bool success = true;
    for(int i = 0; i < M; i++){
        
        bool match = false;
        while(i_d < N){
            if(T[i] == D[i_d]){
                match = true;
                i_d++;
                break;
            }
            i_d++;
        }

        if(i_d == N && !match){
            success = false;
            break;
        }
    }

    if(success){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
