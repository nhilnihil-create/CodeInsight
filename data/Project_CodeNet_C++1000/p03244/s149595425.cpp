#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double pi = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    map<int,int> meven;
    map<int,int> modd;
    int ceven = 0;
    int evenmax = 0;
    int evenmax2 = 0;
    int codd = 0;
    int oddmax = 0;
    int oddmax2 = 0;
    for(int i = 0; i < n; i++){
        if( i % 2 == 0){
            auto ite = meven.find(v[i]);
            if(ite != meven.end()){
                ite -> second = ite -> second + 1;
            }
            else{
                meven.insert(make_pair(v[i],1));
            }
        }
        else{
            auto ite = modd.find(v[i]);
            if(ite != modd.end()){
                ite -> second++;
            }
            else{
                modd.insert(make_pair(v[i],1));
            }
        }
    }
    for(auto ite = meven.begin(); ite != meven.end(); ++ite){
        int temp = ite -> second;
        if(evenmax < temp){
            evenmax = temp;
            ceven = ite -> first;
        }
    }
    for(auto ite = modd.begin(); ite != modd.end(); ++ite){
        if(oddmax < ite -> second){
            oddmax = ite -> second;
            codd = ite -> first;
        }
    }
    for(auto ite = meven.begin(); ite != meven.end(); ++ite){
        int temp = ite -> second;
        if(evenmax2 < temp && ceven != ite -> first){
            evenmax2 = temp;
        }
    }
    for(auto ite = modd.begin(); ite != modd.end(); ++ite){
        int temp = ite -> second;
        if(oddmax2 < temp && codd != ite -> first){
            oddmax2 = temp;
        }
    }
    if(codd != ceven) cout << (n / 2 - oddmax) + (n / 2 - evenmax) << endl;
    else cout << min((n / 2 - oddmax)+(n / 2 - evenmax2),(n / 2 - oddmax2)+(n / 2 - evenmax)) << endl;
    return 0;
}
