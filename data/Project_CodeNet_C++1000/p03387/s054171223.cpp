#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int A, B, C;
    

    cin >> A >> B >> C;

    int nums[3] = {A, B, C};
    sort(nums, nums+3);
    int max_num = nums[2];

    int min_num = nums[0];
    int mid_num = nums[1];

    int count = 0;
    bool over_flag = false;

    REP(i, 60){
        if (mid_num == max_num){
            break;
        }

        min_num += 1;
        mid_num += 1;
        count += 1;        
    }

    REP(i, 60){
        if (min_num == max_num){
            break;
        }

        if (min_num > max_num){
            over_flag = true;
            break;
        }

        min_num += 2;
        count += 1;        
    }

    if (over_flag){
        count += 1;
    }

    cout << count << endl;
}