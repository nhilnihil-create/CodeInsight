#include <iostream>
#include <iomanip>

using namespace std;

double dp[20001][101];

int main(){
    int N;
    int v[20001];
    int v_sect[20001];
    int v_max[20001];
    int t[100];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t[i];
    }
    for(int i = 0; i < 20001; i++){
        v[i] = 1000;
        v_max[i] = 1000;
        v_sect[i] = 1000;
    }
    int t_sum = 0;  
    for(int i = 0; i < N; i++){
        int v_;
        cin >> v_;
        for(int j = 0; j <= t[i]; j++){
            v[t_sum+j] = min(v[t_sum+j], v_);
        }
        for(int j = 0; j < t[i]; j++){
            v_sect[t_sum+j] = v_;
        }
        t_sum += t[i];
    }
    //v[0] = 0;
    //v[t_sum] = 0;
    v_max[0] = 0;
    v_max[t_sum] = 0;
    for(int i = 1; i < t_sum; i++){
        v_max[i] = min(v[i], v_max[i-1]+1);
        //cout << v_max[i] << ' ';
    }
    //cout << endl;
    for(int i = t_sum-1; i >= 1; i--){
        v_max[i] = min(v_max[i], v_max[i+1]+1);
        //cout << v_max[i] << ' ';
    }
    //cout << endl;
    double ans = 0.0;
    for(int i = 1; i <= t_sum; i++){
        if(v_max[i-1] != v_max[i]){
            ans += ((double)(v_max[i-1] + v_max[i]))/2.0;
        }
        if(v_max[i-1] == v_max[i]){
            if(v_sect[i-1] == v_max[i]){
                ans += v_max[i];
                //cout << 'H' << endl;
                //cout << v[0] << ' ' << v[1] << v_max[0] << ' ' << v_max[1] << endl;
            }else{
                ans += v_max[i]+0.25;
            }
        }
    }
    
    std::cout << std::fixed;
    std::cout << std::setprecision(4) << ans << endl;
    //cout << dp[t_sum][1] << endl;
    //cout << dp[t_sum][2] << endl;
}