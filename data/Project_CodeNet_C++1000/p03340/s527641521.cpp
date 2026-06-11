#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n); for (auto &&i : a) cin >> i;
    //
    //
    int right = 1;
    long long ans = 0;
    long long sum = 0;
    sum += a.at(0);
    for (int left = 0; left < n; left++)
    {
        while (right < n && sum + a.at(right) == (sum ^ a.at(right)) )
        {
            sum += a.at(right);
            right++;
        }
        ans += (right - left);
        if(left == right) right++;
        sum -= a.at(left);
    }
    std::cout << ans << endl;
}