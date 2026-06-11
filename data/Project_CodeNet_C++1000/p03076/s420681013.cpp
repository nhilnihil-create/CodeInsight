#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >>e;
    vector<int>nums;
    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);
    nums.push_back(d);
    nums.push_back(e);
    vector<int> vec = {0};
    for(int i=0; i<5; i++){
        if(10-(nums[i]%10)!= 10){
            vec.push_back(10-(nums[i]%10));
        }
    }
    sort(vec.begin(),vec.end());
    int count = 0;
    for(int i=0; i<vec.size()-1; i++){
        count+=vec[i];
    }
    int ans = a+b+c+d+e;
    cout << ans+count <<endl;

}