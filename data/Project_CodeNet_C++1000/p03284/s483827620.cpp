#include <iostream>

using namespace std;

int main()

{
    int N,K;
    cin>>N>>K;
int reminder=N%K;
int div=N/K;
int max=0;
int min=0;
if(reminder>0){reminder=1;}

cout<<div+reminder-div;


    }




