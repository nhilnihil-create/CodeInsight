#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000

int n,a,b,c,ans=INF;
vector<int> l;
/*方針*/
/*
    l[0]        l[1]       l[2]      l[3]   ......   l[n-1]
  　aに使う     aに使う     aに使う    aに使う         aに使う
  　bに使う     bに使う     bに使う    bに使う　　　　　bに使う
  　cに使う     cに使う     cに使う    cに使う         cに使う
  　使わない    使わない    使わない    使わない        使わない

  上のように竹1本につき、a,b,cに使うか、どこにも使わないという4つの選択肢があるので
  上のパターンを全探索する(dfs) O(4^n)で間に合う
  ただし、a,b,cには少なくとも1本を使わなければならないので、a,b,cのいずれか少なくとも
  1本に対して、使用本数が0となる場合は除く
*/

void dfs(int A,int B,int C,int number,int MP){//A:今のaの長さ　B:今のbの長さ　C:今のcの長さ 
    if(number==n){
        if(!(A==0 || B==0 || C==0)){//少なくとも1本は使わなければならない
            ans=min(ans,MP+abs(A-a)+abs(B-b)+abs(C-c));//MP:合成魔法のMP　abs:長さ調節魔法のMP
        }
        return;
    }
        
    dfs(A+l[number],B,C,number+1,MP+10);//l[number]をaに使う
    dfs(A,B+l[number],C,number+1,MP+10);//l[number]をbに使う
    dfs(A,B,C+l[number],number+1,MP+10);//l[number]をcに使う
    dfs(A,B,C,number+1,MP);//l[number]を使わない
    
    return;
}


int main(){
    cin>>n>>a>>b>>c;//a,b,cの長さの竹を3本作りたい
    l.resize(n);
    for(int i=0;i<n;i++){cin>>l[i];}
    dfs(0,0,0,0,0);

    cout<<ans-30<<endl;
    //最初、必ずA==0 B==0 C==0に対して合成をするが、問題文では無に合成できないので、余計な合成分を除く
    return 0;
}