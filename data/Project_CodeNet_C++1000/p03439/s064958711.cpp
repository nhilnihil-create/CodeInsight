#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;



int main() {
    int N;
    cin >> N;
    //0~N-1の間に少なくとも1つ空席がある
    //s(i)!=s(i+2k)となるときには，どこかしらに空席がある。また，i=0,k=(N-1)/2とすると，必ずその様になる点が存在することが示せる。
    vector<string>res(N);
    cout << 0 << endl;
    cin >> res.at(0);
    if (res.at(0) == "Vacant")return 0;
    cout << N - 1 << endl;
    cin >> res.at(N - 1);
    if (res.at(N - 1) == "Vacant")return 0;
    int left = 0, right = N - 1,mid;
    for (size_t i = 0; i < 19; i++)
    {
        mid = left + (right - left) / 2;
        cout << mid << endl;
        cin >> res.at(mid);
        if (res.at(mid) == "Vacant")return 0;
        if ((res.at(mid) == res.at(0) && mid % 2 == 0) || (mid % 2 == 1 && res.at(mid) != res.at(0)))left = mid;
        else right = mid;
    }
    cout << "surrender";
}