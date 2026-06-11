/**
*    author:  souzai32
*    created: 15.08.2020 02:26:08
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
using namespace std;

int main() {

    string s;
    cin >> s;
    int left=0, right=s.size()-1;
    int count=0;
    while(left<=right){
        if(s.at(left)==s.at(right)){
            left++;
            right--;
        }else if(s.at(right)=='x'){
            right--;
            count++;
        }else if(s.at(left)=='x'){
            left++;
            count++;
        }else{
            count=-1;
            break;
        }
    }
    cout << count << endl;

    return 0;
}