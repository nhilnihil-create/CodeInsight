#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define bug(a)       cerr << #a << " : " << a << endl;
#define md 1000000007
#define itc(n) char(n+48)
#define cti(ch) (ch-48)
#define pb push_back
template<class T>void ExEuclid(T n, T m, T &a, T &b, T &gcd){if(m==0){gcd=n;a=1;b=0;return;}ExEuclid(m,n%m,a,b,gcd);T x=a;a=b;b=x-(n/m)*a;}
template<class T>T gcd(T n, T m){if(m==0){return n;}gcd(m,n%m);}
template<class T>T lcm(T n, T m){return (n*m)/gcd(n,m);}
template<class T>string to_string(T n){ostringstream convert;convert<<n;return convert.str();}
template<class T>ll to_int(T s){ll num=0,power=0;for(int i=s.size()-1; i>=0; i--)num+=(pow(10.0,power++)*(s[i]-'0'));return num;}
template<class T>bool is_mod(T n, T m){if(n%m==0)return true;return false;}
template<class T>bool is_upper(T s){for(int i=0; i<s.size(); i++)if(s[i]>90 || s[i]<65)return false;return true;}
template<class T>bool is_lower(T s){for(int i=0; i<s.size(); i++)if(s[i]>122 || s[i]<97)return false;return true;}
template<class T>bool is_palindrome(T s){T s1=s;reverse(s1.begin(),s1.end());if(s==s1)return true;return false;}
template<class T>int digit_sum(T s){int sum=0; for(int i=0; i<s.size(); i++)sum+=cti(s[i]);return sum;}
template<class T>T mod(T n, T m){return ((n%m)+m)%m;}
template<class T>T Big_mod(T base, T power, T MOD){
    if(power==1)return base;
    if(power & 1)return ((base%MOD)*(Big_mod(base,power-1,MOD))%MOD)%MOD;
    else {T temp=(Big_mod(base,power>>1,MOD));return ((temp%MOD)*(temp%MOD))%MOD;}
}
template<class T>T doStringSum(T s1, T s2){int len1=s1.length(), len2=s2.length();
    if(len1<len2)return doStringSum(s2, s1);
    T ans="";int carry=0, i, s;
    for(i=1;i<=len1;i++){s = carry+cti(s1[len1-i]);if(i<=len2)s += cti(s2[len2-i]);
    ans = itc(s%10)+ans;carry = s/10;}if(carry!=0)ans = itc(carry)+ans;
    return ans;
}
template<class T>T dostringmultiply(T s1, T s2){int len1=s1.length(), len2=s2.length();
    if(len1<len2)return dostringmultiply(s2,s1);
    int i,j,p, carry=0;T result, net="", c;
    for(i=len2-1;i>=0;i--){carry=0;result="";c="";
    for(j=len1-1;j>=0;j--){p=cti(s1[j])*cti(s2[i]);result = itc((p+carry)%10)+result;carry=(p+carry)/10;}
    if(carry!=0){c=to_string(carry);result=c+result;}
    for(j=i;j<len2-1;j++)result+="0";net=doStringSum(net,result);}
    return net;
}
template<class T>T nCr(T n, T r)
    {if(r > n - r) r = n - r;T ans = 1;T i;
    for(i = 1; i <= r; i++){ans *=(n-r+i);ans%=md;ans /= i;}
    return ans%md;
}

int main()
{
    fast;
    int n;
    cin>>n;
    cout<<(n-2)*180<<endl;
    return 0;
}
