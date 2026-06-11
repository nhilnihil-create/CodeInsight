#include <bits/stdc++.h>

using namespace std;

#define vv vector< vector< int > >
#define ll long long
#define ALL(a) (a).begin(), (a).end()
const long long mod = 1000000000 + 7;
const long long INF = 9e18;
const double PI = 3.14159265358979323846;

ll gcd(ll a, ll b){if (b == 0) return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int vector_finder(vector<int> vec, int number) {
    auto itr = find(vec.begin(), vec.end(), number);
    size_t index = distance( vec.begin(), itr );
    if (index != vec.size()) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    int s;
    cin >> s;
    vector<int> nums;
    nums.push_back(s);
    int i = 2;
    while(true){
        if (s % 2 == 0){
            s = s / 2;
        }
        else{
            s = 3*s + 1;
        }
        if(vector_finder(nums, s)){
            cout << i << endl;
            return 0;
        }
        else{
            nums.push_back(s);
        }
        i++;
    }
    return 0;
}
