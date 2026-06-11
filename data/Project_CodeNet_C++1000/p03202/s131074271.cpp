#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int lower = 0, upper = n, mid;
    while(upper - lower > 1){
        mid = (upper + lower) / 2;

        bool flag = true;
        map<int, int> string_data;

        for(int i=0; i+1<n; i++){
            if(a[i+1] > a[i]) continue;

            while(string_data.empty() == false){
                auto sd = *prev(string_data.end());
                if(sd.first >= a[i+1]) string_data.erase(sd.first);
                else break;
            }                

            int j = a[i+1] - 1;
            while(string_data.find(j) != string_data.end() && string_data[j] == mid - 1){
                string_data.erase(j);
                j -= 1;
            }
            if(j < 0){ flag = false; break; }

            if(string_data.find(j) == string_data.end()) string_data[j] = 0;
            string_data[j] += 1;

            if(string_data[j] >= mid){ flag = false; break; }
        }

        if(flag == true)  upper = mid;
        if(flag == false) lower = mid;
    }
    cout << upper << endl;
    return 0;
}