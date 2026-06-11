    #include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back
     
    const int mn=39;
    typedef long long ll;
     
    int n;
    char s[mn];
     
    unordered_map<size_t,int> h;
    hash<string> hs;
     
    string t;
    inline size_t gethash(string &s){
        return hs(s);
    }
     
    int main() {
        scanf("%d",&n);
        scanf("%s",s);
     
        ll ans=0;
     
        for(int i=0;i<(1<<n);i++){
            t.clear();
            for(int j=0;j<n;j++){
                if ((1<<j)&i) t+=s[j];
            }
            for(int j=n-1;j>=0;j--){
                if (((1<<j)&i)==0) t+=toupper(s[j]);
            }
            h[gethash(t)]++;
        }
     
        reverse(s,s+n*2);
        for(int i=0;i<(1<<n);i++){
            t.clear();
            for(int j=0;j<n;j++){
                if ((1<<j)&i) t+=s[j];
            }
            for(int j=n-1;j>=0;j--){
                if (((1<<j)&i)==0) t+=toupper(s[j]);
            }
            ans+=h[gethash(t)];
        }
        printf("%lld\n",ans);
        return 0;
    }