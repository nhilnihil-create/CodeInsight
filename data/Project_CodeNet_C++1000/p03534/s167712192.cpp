#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<set>
#define N 500005
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios::sync_with_stdio(false)
#define INF 1000000010
template<typename T> inline T max(T a,T b,T c){
    return max(a,max(b,c));
}
template<typename T> inline T min(T a,T b,T c){
    return min(a,min(b,c));
}
template<typename T> inline T max(T a,T b,T c,T d){
    return max(a,max(b,c,d));
}
template<typename T> inline T min(T a,T b,T c,T d){
    return min(a,min(b,c,d));
}
const int  dx[]={0,1,0,-1,0,1,-1,1,-1};
const int  dy[]={0,0,1,0,-1,1,-1,-1,1};

typedef long long ll;
using namespace std;
//coding...........................................
int main()
{
     char a[N];
     int num[5]={0};
     int flag=0;
     scanf("%s",a);
     int len=strlen(a);
     for (int i=0;i<len;i++)
        num[a[i]-'a']++;
     sort(num,num+3);
     if (abs(num[2]-num[1])<=1&&abs(num[2]-num[0])<=1&&abs(num[1]-num[0])<=1)
        cout << "YES" << endl;
     else
        cout << "NO" << endl;
    return 0;
}
