#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

vector<int> pow2(){
    vector<int> vec(1,1);
    for(int i=0; vec[i]<(int)MOD; i++){
        vec.push_back(2*vec[i]);
    }
    return vec;
}

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;

    map<int,int> m;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        m[a]++;
    }

    vector<int> vec=pow2();
    //cout_vec(vec);
    int ans=0;
    for(auto it=m.rbegin(); it!=m.rend(); it++){
        int key=it->first;
        int cnt=it->second;
        if(cnt==0)continue;

        auto tg=upper_bound(vec.begin(),vec.end(),key);
        //cout << key << ' ' << *tg-key << endl;
        if(tg!=vec.end() && m.count(*tg-key)){
            if(key==*tg-key && m[*tg-key]>=2){
                int num=m[key]/2;
                m[key]-=2*num;
                ans+=num;
            }else if(key!=*tg-key && m[*tg-key]>0){
                int num=min(m[key],m[*tg-key]);
                m[key]-=num;
                m[*tg-key]-=num;
                ans+=num;
            }
        }
    }
    cout << ans << endl;
}