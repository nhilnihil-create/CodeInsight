#include <iostream>
#include <cstdio>
using namespace std;

struct SpecialNum{
    long long value;
    bool index3;
    bool index5;
    bool index7;
    SpecialNum(long long v,bool i3,bool i5,bool i7): value(v),index3(i3),index5(i5),index7(i7) {}
};


void LianXianDan(int &sum,SpecialNum x,int T){
    long long v=x.value;
    bool index3=x.index3;
    bool index5=x.index5;
    bool index7=x.index7;
    if(v>T){
        return;
    }
    else if(v<=T){
        if(index3 && index5 && index7)
            sum++;
        long long v3=v*10+3;
        SpecialNum x3=SpecialNum(v3,true,index5,index7);
        long long v5=v*10+5;
        SpecialNum x5=SpecialNum(v5,index3,true,index7);
        long long v7=v*10+7;
        SpecialNum x7=SpecialNum(v7,index3,index5,true);
        LianXianDan(sum,x3,T);
        LianXianDan(sum,x5,T);
        LianXianDan(sum,x7,T);
        return;
    }
}

int main()
{
    int T;
    while(cin>>T){
        SpecialNum x1=SpecialNum(0,false,false,false);
        int sum=0;
        LianXianDan(sum,x1,T);
        cout<<sum<<endl;
    }
    return 0;
}

