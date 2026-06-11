#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int K;
    cin >> K;
    int len_s = s.size();
    vector<string> vec(0);
    if (len_s == 1){
        cout << s << endl;
    }
    if (len_s == 2){
        vec.push_back(s.substr(0,1));
        vec.push_back(s.substr(1,1));
        vec.push_back(s.substr(0,2));
        sort(all(vec));
    }
    if (len_s == 3){
        rep(i,3){
            vec.push_back(s.substr(i,1));
        }
        vec.push_back(s.substr(0,2));
        vec.push_back(s.substr(1,2));
        vec.push_back(s.substr(0,3));
        sort(all(vec));
    }
    if (len_s == 4){
        rep(i,4){
            vec.push_back(s.substr(i,1));
        }
        rep(i,3){
            vec.push_back(s.substr(i,2));
        }
        vec.push_back(s.substr(0,3));
        vec.push_back(s.substr(1,3));
        vec.push_back(s.substr(0,4));
        sort(all(vec));
    }
    if (len_s >= 5){
        rep(i,len_s){
            vec.push_back(s.substr(i,1));
        }
        rep(i,len_s - 1){
            vec.push_back(s.substr(i,2));
        }
        rep(i,len_s - 2){
            vec.push_back(s.substr(i,3));
        }
        rep(i,len_s - 3){
            vec.push_back(s.substr(i,4));
        }
        rep(i,len_s - 4){
            vec.push_back(s.substr(i,5));
        }
        sort(all(vec));
    }
    if (len_s != 1){
        int count = 1;
        int len_vec = vec.size();
        vec.push_back("a");
        rep(i,len_vec){
            if (count == K){
                cout << vec[i] << endl;
                break;
            }
            if (vec[i] != vec[i + 1]){
                count++;
            }
        }
    }
}
