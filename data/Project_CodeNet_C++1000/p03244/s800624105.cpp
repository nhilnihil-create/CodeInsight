#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    int N;
    cin >> N;
    vector<int> V1(100010), V2(100010);
    rep(i, N/2){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        V1.at(tmp1)++;
        V2.at(tmp2)++;
    }

    vector<int> V1_sort = V1, V2_sort = V2;
    int V1_max = 0, V2_max = 0, V1_max2, V2_max2, V1_a, V2_a;

    sort(V1_sort.rbegin(), V1_sort.rend());
    sort(V2_sort.rbegin(), V2_sort.rend());

    V1_max = V1_sort.at(0);
    V1_max2 = V1_sort.at(1);
    V2_max = V2_sort.at(0);
    V2_max2 = V2_sort.at(1);

    int ans = 0;
    for(int i = 1; i < N/2; i++){
        ans += V1_sort.at(i) + V2_sort.at(i);
    }

    rep(i, 100010){
        if(V1.at(i) == V1_max){
            V1_a = i;
        }
        
        if(V2.at(i) == V2_max){
            V2_a = i;
        }
    }

    if(V1_a == V2_a){
        int change1 = V1_max - V1_max2, change2 = V2_max - V2_max2;
        if(change1 > change2) ans += change2;
        else ans += change1;
    }

    cout << ans << endl;
}