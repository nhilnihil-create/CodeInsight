  #include<bits/stdc++.h>
  using namespace std;
  int c[102];
  int main()
  {  string s,a,b;
       int n;
       cin>>n;
       cin>>s>>a>>b;
       for(int i=0;i<n;i++)
       {
           if(s[i]==a[i]&&s[i]==b[i])
             c[i]=0;
           else if(s[i]==a[i]||a[i]==b[i]||s[i]==b[i])
            c[i]=1;
           else c[i]=2;
       }
       int sum=0;
       for(int i=0;i<n;i++)
        sum+=c[i];
        cout<<sum<<endl;
      return 0;
  }
