#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int total_t = 0;
    vector<int> t(n), v(n);
    for(int i=0; i<n; i++){
        cin >> t[i];
        total_t += t[i];
    }
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    vector<int> maxv(2 * total_t+1, 1000);// in 0.5 increment
    maxv[0] = 0;
    maxv[2*total_t] = 0;
    int current = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=2*t[i]; j++){
            //cout << current + j << " ";
            if(current + j <= 2 * total_t / 2) maxv[current + j] = min({maxv[current + j], 2 * v[i], current + j});
            else maxv[current + j] = min({maxv[current + j], 2 * v[i], 2 * total_t - (current + j)});
            //cout << maxv[current + j] << endl;
        }
        current += 2 * t[i];
    }
    for(int i=1; i<=2*total_t; i++){
        for(int j=i+1; j<=2*total_t; j++){
            maxv[i] = min(maxv[i], maxv[j] + (j-i));
        }
        //cout << i << " " << maxv[i] << endl;
    }

    double ans = 0;
    int current_v = 0;
    for(int i=1; i<=2*total_t; i++){// be careful with the scaling by 2
        if(current_v < maxv[i]){
            current_v += 1;
            ans += (current_v / 2.0 + (current_v-1) / 2.0) * 0.5 / 2.0;// trapezoid
        }
        else if(current_v > maxv[i]){
            current_v -= 1;
            ans += (current_v / 2.0 + (current_v+1) / 2.0) * 0.5 / 2.0;// trapezoid
        }
        else{// current_v == maxv[i]
            ans += (current_v / 2.0) * 0.5;// rectangle
        }
        //cout << i << " : " << current_v / 2.0 << endl;
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}