#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long>a(n);
    vector<long long>b(n);

    long long sum_a = 0, sum_b = 0;

    for(long long i = 0; i < n; i++){
        cin >> a[i];
        sum_a += a[i];
    }

    for(long long i = 0; i < n; i++){
        cin >> b[i];
        sum_b += b[i];
    }

    if(sum_a < sum_b){
        printf("-1\n");
        return 0;
    }

    vector<long long> plus;
    vector<long long> minus;

    for(long long i = 0; i < n; i++){
        if(a[i] - b[i] > 0){
            plus.push_back(a[i]-b[i]);
        }
        else if(a[i] - b[i] < 0){
            minus.push_back(b[i]-a[i]);
        }
    }

    sort(plus.begin(), plus.end(), greater<long long>());
    sort(minus.begin(), minus.end(), greater<long long>());

    if(minus.size() == 0){
        printf("0\n");
        return 0;
    }

    long long count = 0;

    while(minus.size() != 0){
        if(plus[0] > minus[0]){
            plus[0] -= minus[0];
            count++;
            minus.erase(minus.begin());
        }
        else if(plus[0] < minus[0]){
            minus[0] -= plus[0];
            count++;
            plus.erase(plus.begin());
        }
        else{
            count += 2;
            minus.erase(minus.begin());
            plus.erase(plus.begin());
        }
    }

    cout << count+1 << endl;

    return 0;


}