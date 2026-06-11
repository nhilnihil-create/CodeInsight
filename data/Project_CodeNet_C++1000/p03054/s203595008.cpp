/*やったぜ。　投稿者：変態糞土方 (8月16日（水）07時14分22秒)

昨日の8月15日にいつもの浮浪者のおっさん（60歳）と先日メールくれた汚れ好きの土方のにいちゃん

（45歳）とわし（53歳）の3人で県北にある川の土手の下で盛りあったぜ。

今日は明日が休みなんでコンビニで酒とつまみを買ってから滅多に人が来ない所なんで、

そこでしこたま酒を飲んでからやりはじめたんや。

3人でちんぽ舐めあいながら地下足袋だけになり持って来たいちぢく浣腸を3本ずつ入れあった。

しばらくしたら、けつの穴がひくひくして来るし、糞が出口を求めて腹の中でぐるぐるしている。

浮浪者のおっさんにけつの穴をなめさせながら、兄ちゃんのけつの穴を舐めてたら、

先に兄ちゃんがわしの口に糞をドバーっと出して来た。

それと同時におっさんもわしも糞を出したんや。もう顔中、糞まみれや、

3人で出した糞を手で掬いながらお互いの体にぬりあったり、

糞まみれのちんぽを舐めあって小便で浣腸したりした。ああ～～たまらねえぜ。

しばらくやりまくってから又浣腸をしあうともう気が狂う程気持ちええんじゃ。

浮浪者のおっさんのけつの穴にわしのちんぽを突うずるっ込んでやると

けつの穴が糞と小便でずるずるして気持ちが良い。

にいちゃんもおっさんの口にちんぽ突っ込んで腰をつかって居る。

糞まみれのおっさんのちんぽを掻きながら、思い切り射精したんや。

それからは、もうめちゃくちゃにおっさんと兄ちゃんの糞ちんぽを舐めあい、

糞を塗りあい、二回も男汁を出した。もう一度やりたいぜ。

やはり大勢で糞まみれになると最高やで。こんな、変態親父と糞あそびしないか。

ああ～～早く糞まみれになろうぜ。

岡山の県北であえる奴なら最高や。わしは163*90*53,おっさんは165*75*60、や

糞まみれでやりたいやつ、至急、メールくれや。

土方姿のまま浣腸して、糞だらけでやろうや。*/
#include "bits/stdc++.h"
#include <numeric>
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define llMIN numeric_limits<long long>::min()
#define intMIN numeric_limits<int>::min()
#define d_5 100000
#define d9_7 1000000007
#define vll vector<vector<long long>>
#define vl vector<long long>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pf push_front
#define ld long double

int main(void){
  int h,w,n;
  cin>>h>>w>>n;
  ll sr,sc;
  cin>>sr>>sc;
  string s,t;
  cin>>s>>t;
  reverse(s.begin(),s.end());
  reverse(t.begin(),t.end());
  int flag=0;
  sr--;sc--;
  int maxy=h,maxx=w,minx=0,miny=0;
  int now1=0;
  int now2=0;
  int now3=w-1;
  int now4=h-1;
  rep(i,n){
    if(t[i]=='D' && now1 >0){
      now1--;
    }
    if(s[i]=='U'){
      now1++;
    }
    miny=max(miny,now1);

    if(t[i]=='R' && now2>0){
      now2--;
    }
    if(s[i]=='L'){
      now2++;
    }
    minx=max(minx,now2);

    if(t[i]=='L' && now3 <w-1){
      now3++;
    }
    if(s[i]=='R'){
      now3--;
    }
    maxx=min(maxx,now3);

    if(t[i]=='U' && now4 <h-1){
      now4++;
    }
    if(s[i]=='D'){
      now4--;
    }
    maxy=min(maxy,now4);

    if(now1>now4 || now2>now3){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  //cout<<minx<<" "<<maxx<<" "<<miny<<" "<<maxy<<" ";
  /*if(minx<=sr && sr<=maxx && miny <= sc && sc <= maxy && minx<=maxx && miny <=maxy){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }*/
  if(now1<=sr && sr<=now4 && now2 <= sc && sc <= now3){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
  return 0;
}
