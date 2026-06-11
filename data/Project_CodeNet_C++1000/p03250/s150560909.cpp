#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;

int main() {
    vector<int> arr(3);
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr.begin(), arr.end());
    cout<<arr[0] + arr[1] + arr[2]*10<<endl;
}

