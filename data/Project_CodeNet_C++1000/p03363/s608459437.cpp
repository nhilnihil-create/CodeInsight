#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long> total(n, 0);
    vector<long long> car;
    total[0] = a[0];
    car.push_back(total[0]);
    long long ans = 0;
    if(total[0] == 0) ans++;
    
    
    for(int i = 1; i < n ; i++){
        total[i] = total[i-1] + a[i];
        car.push_back(total[i]);
        if(total[i] == 0){
            ans++;
        }
    }
    sort(car.begin(), car.end());
    long long num = 1;

    //  for(int i = 0; i < car.size();i++){
    //      cout << " car: " << car[i];
    //  }
    //  cout << endl;

    for(int i =1; i<car.size(); i++){
        if(car[i-1] == car[i]){
            num++;
        }else{
            ans += num * (num-1)/2;
            //cout << "ans: " << ans << endl;
            num = 1;
        }
    }
    ans += num * (num-1)/2;
    cout << ans << endl;
    return 0;
}