#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#include<map>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> p{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
    vector<int> c(100,0);
    int s = p.size();
    for(int i=2; i<N+1; i++){
        int tmp = i;
        for(int j=0; j<s; j++){
            if(tmp%p[j] == 0){
                while(tmp%p[j]==0){
                    c[p[j]]++;
                    tmp /= p[j];
                }
            }
        }
    }
    int cnt2, cnt4, cnt14, cnt24, cnt74;
    cnt2 = 0;
    cnt4 = 0;
    cnt14 = 0;
    cnt24 = 0;
    cnt74 = 0;
    for(int i=0; i<100; i++){
        if(c[i] >= 74) cnt74++;
        if(c[i] >= 24) cnt24++;
        if(c[i] >= 14) cnt14++;
        if(c[i] >= 4)  cnt4++;
        if(c[i] >= 2)  cnt2++;
    }
    int ans = 0;
    ans += cnt74;
    ans += cnt24*(cnt2-1);
    ans += cnt14*(cnt4-1);
    ans += cnt4*(cnt4-1)*(cnt4-2)/2;
    ans += cnt4*(cnt4-1)*(cnt2-cnt4)/2;
    cout << ans;
}