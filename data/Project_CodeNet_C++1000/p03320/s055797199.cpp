#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll sum(ll x){
    ll ss = 0;
    string s = to_string(x);
    for(int i = 0; i < s.size(); ++i)
        ss += (s[i] - '0');
    return ss;
}

//bool check(ll x){
//    string s = to_string(x);
//    for(int i = 0; i < s.size(); ++i)if(s[i] != '9')return false;
//    return true;
//}

bool check(ll a, ll b){
    //if a/s(a) >= b/s(b) return true else false

    long double ans1 = a*1.0/sum(a);
    long double ans2 = b*1.0/sum(b);

    return ans1 >= ans2;
}

int main(){

    cout << fixed << setprecision(6);

//    long double array[511112] = {0.0};

    ll i, j, k;
    cin >> k;

    ll ct = 1;
    ll p = 1;
    ll p2 = 10;

//    cout << check(18, 9) << endl;

    for(i = 0; i < k; ++i){
        cout << ct << endl;
        if(check(ct + p2, ct + p)){
            ct = ct + p;
        }
        else{
            ct = ct + p2;
            p2 = p2 * 10;
            p = p * 10;
        }
    }

//    for(i = 1; i <= 511111; ++i){
////        cout << i << " " << sum(i) << " -- ";
//        long double x = i*1.0/sum(i);
//        array[i] = x;
//
////        cout << x << endl;
//    }
//
//    for(i = 1; i <= 511111; ++i){
//        for(j = i + 1; j <= 511111; ++j){
//            if(array[i] > array[j])break;
//        }
//        if(j > 511111)cout << i << endl;
//    }
//
//    ll ct = 1;
//
//    ll p = 1;
//
//    for(ll i = 0; i < k; ++i){
//        cout << ct << endl;
//        if(check(ct)){
//            p = p * 10;
//        }
//        ct = ct + p;
//    }


    return 0;
}