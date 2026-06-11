#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1e5+2;
char a[N];
int main()
{
    string s;
    cin>>s;
    int z=0,o=0;
    int sum=0;
    string lst="";
    int j=0;
    int n=s.size();
    for(int i=0;i<n;i++){
            if(lst=="")
            {
                lst+=s[i];
                j=0;
                continue;
            }
       if(s[i]!=lst[j]){
            lst.pop_back();
            j--;
            sum++;
       }
       else{
        lst+=s[i];
        j++;
       }
    }
    printf("%d",sum*2);

}
