//g++ -std=c++14 test.cpp -o test.out
 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;
 
LL N;
LL D[50];
 
LL ans = 0;
 
void solve(){
    vector<int> time_num(13,0);//時刻iの人数をtime_num[i]とする
    time_num[0]++;//高橋くんの都市の分
    for(int i=0;i<N;i++) time_num[D[i]]++;
    //時差0と12は一人までしか許容不可
    if(time_num[0]>=2 || time_num[12]>=2) return;
    //2人までなら時刻i、時刻24-iの二箇所に配置できるが、
    //3人以上いると必ず、最低誰か2人は時刻が被って時差の最小値が0になってしまう
    for(int i=1;i<=11;i++){
        if(time_num[i]>=3) return;
    }

    //被りがないことが保証されたなら次の工程へ
    //被りがないことが保証=各時刻に対し、該当者が必ず2人以下
    vector<int> time_alone,time_twin;//それぞれ、1人しかいない時間帯、2人いる時間帯を格納
    for(int i=1;i<=11;i++){
        if(time_num[i]==1) time_alone.push_back(i);
        if(time_num[i]==2) time_twin.push_back(i);
    }

    //時間iに人がいるかどうかをtime_arrayのibit目が1かどうかで表す
    int time_array = 1;//高橋くんの分
    for(int time : time_twin){
        //時間timeの2人をtime[bit]目と24-time[bit]目にそれぞれ配置
        time_array |= (1<<time);
        time_array |= (1<<(24-time));
    }
    if(time_num[12]==1) time_array |= (1<<12);

    auto search = [&](int bits){
        int min_diff = INF_INT;
        for(int i=0;i<24;i++){
            if(!((bits>>i)&1)) continue;
            for(int j=i+1;j<24;j++){
                if(!((bits>>j)&1)) continue;
                min_diff = min(min_diff,j-i);
                min_diff = min(min_diff,24-(j-i));
            }
        }
        return min_diff;
    };

    if(time_alone.size()==0){
        ans = search(time_array);
        return;
    }

     // auto show_bit = [&](int x){
     //    for(int i=0;i<24;i++) cout << ((x>>i)&1);
     //        cout << endl;
     // };

    //一人しかいない時間帯iについて、
    //その一人をiに配置するのか、24-iに配置するのかで全探索
    int numof_alone = time_alone.size();
    for(int bit=0;bit<(1<<numof_alone);bit++){
        //bitのi[bit]目が立っていれば、
        //時刻time_alone[i]に一人配置、
        //立っていないなら24-time_alone[i]に一人配置する
        int array = time_array;
        //bitのi[bit]目を見る
        for(int i=0;i<numof_alone;i++){
            if((bit>>i)&1) array |= (1<<time_alone[i]);
            else array |= (1<<(24-time_alone[i]));
        }
        //show_bit(array);

        //arrayのibit目が立っていれば時刻iに一人いる
        //arrayのjbit目が立っていれば時刻jに一人いる
        ans = max(ans,(LL)search(array));
    }
}
 
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> D[i];
 
    solve();
 
    cout << ans << endl;
    return 0;
}