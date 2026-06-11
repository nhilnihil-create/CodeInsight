#include <vector>
#include<stdio.h>
#include<string.h>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <set>
#include<cstring>
#define Max 0x3F3F3F
#define ll long long
#define MODD 1000000007
#define  pii  pair<int,int>
#include<stdio.h>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;cin >>a>>b;
    cout<<100<<" "<<100<<endl;;
    for(int i=0;i<50;i++){
        for(int j=0;j<100;j++){
            if(i==0)cout<<".";
            else if(i%2){
                if(j%2==1&&b>1)cout<<"#",b--;
                else cout<<".";
            }
            else cout<<".";
        }
        cout<<endl;
    }a--;
    for(int i=0;i<50;i++){
        for(int j=0;j<100;j++){
            if(i==0)cout<<"#";
            else if(i%2){
                if(j%2==1&&a>0)cout<<".",a--;
                else cout<<"#";
            }
            else cout<<"#";
        }cout<<endl;
    }
    return 0;
}
