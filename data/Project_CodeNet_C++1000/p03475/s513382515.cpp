#include <bits/stdc++.h>
using namespace std;
int N;
int c[505], s[505], f[505];

int main(void){
    cin >> N;
    for (int i=0; i<N-1; i++){
        cin >> c[i] >> s[i] >> f[i];
    }
    
    for (int i=0; i<N; i++){
        int curr_time = s[i];
        curr_time += c[i];
        // cout << curr_time << endl;
        for (int j=i+1; j<N-1; j++){
            // cout << curr_time  % s[j] << endl;
            if (curr_time >= s[j]){
                if(curr_time % f[j] != 0) curr_time += f[j] - (curr_time % f[j]);
            }else{
                curr_time = s[j];
            }
            // cout << curr_time << endl;
            curr_time += c[j];
            
        }
        cout << curr_time << endl;
    }
    
}
