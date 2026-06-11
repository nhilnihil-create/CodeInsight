#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    vector<int> vec;
    while(n--){
        int a;
        cin >> a;
        int count = 0;
        while(a>=0){
            if(a%2==0){
                a/=2;
                count++;
            }else{
                break;
            }
        }
        vec.push_back(count);
    }
    vector<int>::iterator ans;
    ans = min_element(vec.begin(),vec.end());
    cout << *ans <<endl;
}