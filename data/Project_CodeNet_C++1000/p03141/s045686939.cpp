#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
const double pi = 3.141592653589793;
int main(){
    int n;
    cin>>n;
    vector<pair<int64_t,int>> T_A(n),A_T(n);
    vector<int64_t> a(n),b(n);
    priority_queue<pair<int64_t,int>> taq,atq,dish;
    rep(i,n){
        cin>>a[i]>>b[i];
        T_A[i] = mp(a[i]-b[i],i);
        taq.push(mp(b[i]-a[i],i));
        A_T[i] = mp(b[i]-a[i],i);
        atq.push(mp(a[i]-b[i],i));
        dish.push(mp(a[i]+b[i],i));
    }
    vector<bool> eaten(n,false);
    all(T_A),all(A_T);
    int64_t tp=0,ap=0;
    int turn = 0;
    while(turn<n){
        //if(turn%2==0){//高橋のターン
            /*
            while(eaten[taq.top().second]){
                taq.pop();//もう食べたことあったら、削除して次
            }
            */
           while(eaten[dish.top().second]){
               dish.pop();
           }
           eaten[dish.top().second]=true;
           if(turn%2==0){
           tp += a[dish.top().second];
           }
           else{
               ap += b[dish.top().second];
           }
           dish.pop();
            //eaten[taq.top().second]=true;
            //tp += a[taq.top().second];
            //taq.pop();
        //}
        /*
        else{//青木のターン
            while(eaten[atq.top().second]){
                atq.pop();//もう食べたことあったら、削除して次
            }
            eaten[atq.top().second]=true;
            ap += b[atq.top().second];
            atq.pop();
        }
        */
        turn++;
    }
    cout<<tp-ap<<endl;
}