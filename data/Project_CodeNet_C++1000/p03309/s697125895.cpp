#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll N, n, b, ans(0),min(1000000000),ans1(0),ans2(0),b1,b2;
    double num;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> n;
        v.push_back(n - i - 1);
    }
    sort(v.begin(), v.end());
    if(N%2==1){
        b=v[(N-1)/2];
        min=0;
        for (int i = 0; i < N; i++){
            min += abs(v[i] - b);
        }
    }else{
        b1=v[N/2-1];
        b2=v[N/2];
        for (int i = 0; i < N; i++){
                ans1 += abs(v[i] - b1);
                ans2 += abs(v[i]-b2);
        }
            if(b2>b1){
                min=ans1;
            }else{
                min=ans2;
            }
        }

    cout << min;
}