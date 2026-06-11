#include <bits/stdc++.h>
using namespace std;

//関数
bool ans2(long A,long B,long C,long D){
    
    if(A<B) return false;//最初から無理なやつ
    
    if(C<A){//補充域に入れるかチェック
    A=A%B;
    A=(C+B-A)-(C+B-A)%B-B+A;//Aとmod Bで等しいようなC以下の整数で最大のもの(補充直前)にする。
    
    if(A<0) return false;//最初から無理なやつ
    }
    
    if(B==D) return true;//補充できたならこいつは即OK
    
    if(B>D) return false;//補充できたならこいつは即OUT
    
    //0<=A<=Cから補充が始まる、B<Dなる状況を考える。
    
    if(C>=B) return true;//必ず補充域に入る。
    
    //0<=A<=Cから補充が始まる、C<B<Dなる状況を考える。→本数が昼で(C,B)に入ることと不可能が同値
    
    long d=D%B;//D足してBを引いていくと前よりどのくらい増えるか→Aからmod Bでd増やしてって(C,B)に入るとOUT
    d=__gcd(d,B);//最大公約数とって、mod dでAと同値な元が(C,B)にあるか見る。
    A=A%d;
    if((C-A)-(C-A)%d+d+A <B) return false;//Cより真に大きいmod dでAになる元がBより小さい⇔mod dでAと同値な元が(C,B)にある
    
    return true;
}
//main関数
int main() {
    
    
    //入力
        
    
    //計算
    
    
    //出力
    long T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        long A,B,C,D;
        cin>>A>>B>>C>>D;
        if(ans2(A,B,C,D)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

}