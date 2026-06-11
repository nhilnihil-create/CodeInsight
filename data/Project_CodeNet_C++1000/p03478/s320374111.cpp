#include <iostream>

using namespace std;

int N, A, B;
int ans;

void OneDigit(){
    for(int i = 0; i <= 9; i++){
        if(i > N){ break; }
        if(i >= A && i <= B){ ans += i; }
    }
}
void TwoDigit(){
    int mycount;
    if(N >= 10){
        for(int i = 10; i <= 99; i++){
            if(i > N){ break; }
            mycount = 0;
            mycount += i % 10;
            mycount += i / 10;
            if(mycount >= A && mycount <= B){ ans += i; }
        }
    }
}
void ThreeDigit(){
    int mycount, temp;
    if(N >= 100){
        for(int i = 100; i <= 999; i++){
            if(i > N){ break; }
            mycount = 0;
            temp = i;
            mycount += temp % 10;
            temp /= 10;
            mycount += temp % 10;
            mycount += temp / 10;
            if(mycount >= A && mycount <= B){ ans += i; }
        }
    }
}
void FourDigit(){
    int mycount, temp;
    if(N >= 1000){
        for(int i = 1000; i <= 9999; i++){
            if(i > N){ break; }
            mycount = 0;
            temp = i;
            mycount += temp % 10;
            temp /= 10;
            mycount += temp % 10;
            temp /= 10;
            mycount += temp % 10;
            mycount += temp / 10;
            if(mycount >= A && mycount <= B){ ans += i; }
        }
    }
}

int main()
{
    ans = 0;
    cin>>N>>A>>B;

    OneDigit();
    TwoDigit();
    ThreeDigit();
    FourDigit();
    if(N == 10000){
        if(A <= 1 && B >= 1){ ans += 10000; }
    }
    cout<<ans<<endl;

    return 0;
}