#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<iomanip>
#include<unordered_map>

using namespace std;
typedef long long ll;

ll dx[] = {1, 0};
ll dy[] = {0, 1};

int main()
{
    ll N;
    vector<ll> a(5);
    cin >> N >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    sort(a.begin(), a.end());
    cout << (ll)ceil((double)N/a[0])+4LL <<endl;
}
