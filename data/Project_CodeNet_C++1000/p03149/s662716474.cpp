#include "./bits/stdc++.h"

#include <vector>
#include <iostream>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define linf 122337203685477000

using namespace std;

typedef long long ll;

/*
vector.push_back()
vector<int> hoge(3,-1); {-1,-1,-1}
vector<vector<int>> hogehoge(2,vector<int>(2,-1)); {{-1,-1},{-1,-1}} 
cin >>temp;
scanf("%d %d %d",&A,&B,&Q);
sort(a.begin(),a.end());
a.push_back(4000000000000);
a.insert(a.begin(),-1000000000000);
upper_bound(a.begin(),a.end(),x); // list[i] > x のイテレータ取得. *itrで数値化 
    std::priority_queue<
      int,
      std::vector<int>,
      decltype(compare) // 比較関数オブジェクトを指定
    > que(comp);
*/
template <typename T> void debug(T arr);
template <typename T> void debug (T arr, int dim);



int main(void){
    vector<ll> arr(4);
    rep(i,4){
        scanf("%lld",&arr[i]);
    }
    vector<ll> tar;
    tar.push_back(1);
    tar.push_back(7);
    tar.push_back(9);
    tar.push_back(4);

    bool flag = true;
    rep(i,4){
        ll count = 0;
        rep(j,4){
            if(tar[i] == arr[j]){
                count += 1;
            }
        }
        if (count != 1){
            flag = false;
        }
    }
    if (flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }



};


template <typename T> void debug(T arr){
    for (auto col:arr){
        cout << col << " ";
    }
    cout <<endl;
};

template <typename T> void debug (T arr, int dim){
    for (auto raw:arr){
        for(auto col:raw){
            cout << col << " ";
        }
        cout << endl;
    }
};
