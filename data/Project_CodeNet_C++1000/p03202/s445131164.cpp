#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n;
int a[200100];
int digit;
stack<i_i> now;

void printer(){
    stack<i_i> sub;
    while(!now.empty()){
        sub.push(now.top());
        now.pop();
    }
    while(!sub.empty()){
        cout << sub.top().first << " " << sub.top().second << endl;
        now.push(sub.top());
        sub.pop();
    }
}

bool add(int digit_now, int maxi){
    if(maxi == 0) return false;
    //cout << "add to " << digit_now << endl;
    //printer();
    if(now.empty()){
        now.push({digit_now, 1});
        return true;
    }
    if(now.top().first < digit_now){
        now.push({digit_now, 1});
        return true;
    }
    if(now.top().second < maxi){
        int New = now.top().second + 1;
        now.pop();
        now.push({digit_now, New});
        return true;
    }
    if(digit_now == 1){
        //cout << "Failed " << maxi << endl;
        return false;
    }
    now.pop();
    return add(digit_now - 1, maxi);
}

bool checker(int maxi){
    //cout << endl << endl << endl << maxi << endl;
    digit = 0;
    while(!now.empty()) now.pop();
    for(int i = 1; i <= n; i++){
        //cout << endl << i << endl << endl;
        //printer();
        if(a[i] > digit){
            digit = a[i];
            continue;
        }
        digit = a[i];
        while(!now.empty()){
            i_i next = now.top();
            if(next.first <= digit) break;
            now.pop();
        }
        if(!add(digit, maxi)) return false;
    }
    return true;
}

int main() {
    //cout.precision(10);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ok = n;
    int ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(checker(mid - 1)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
