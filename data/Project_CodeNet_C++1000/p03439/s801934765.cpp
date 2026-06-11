#include <iostream>
#include <cstdio>
using namespace std;

bool betemp(string sleft, string sright, long long left, long long right){
    if(sleft == sright) return (right - left) % 2 == 1;
    else return (right - left) % 2 == 0;
}

void solve(long long n){
    string vac = "Vacant";

    string sleft;
    string sright;
    string str;

    long long left = 0;
    long long right = n/2;

    cout << left << endl;
    cin >> sleft;
    if(sleft == vac) return;

    cout << right << endl;
    cin >> sright;
    if(sright == vac) return;

    if(betemp(sleft, sright, left, right) == false){
        swap(sleft, sright);
        left = right;
        right = n;
    }

    while(right - left > 1){
        long long mid = (left + right)/2;
        cout << mid << endl;
        cin >> str;
        if(str == vac) return;
        if(betemp(sleft, str, left, mid) == true) sright = str, right = mid;
        else sleft = str, left = mid;
    } 
}

int main(){
    long long n;
    cin >> n;

    solve(n);
    return 0;
}