#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t;
    cin >> n;
    vector<int> start(n - 1),interval(n - 1),req_time(n - 1);
    for(int i = 0;i < n - 1;i++){
        cin >> req_time[i] >> start[i] >> interval[i];
    }
    for(int i = 0;i < n - 1;i++){
        t = 0;
        for(int j = i;j < n - 1;j++){
            if(t < start[j])t = t + (start[j] - t);
            else if(t % interval[j] != 0) t += interval[j] - (t % interval[j]);
            t += req_time[j];
        }
        cout << t << endl;
    }
    cout << 0 << endl;
}