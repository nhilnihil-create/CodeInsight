 #include <iostream>
    #include <bits/stdc++.h>
    #include <map>


    using namespace std;


    int main()
    {
      int n,k;
      cin>>n>>k;
      int arr[n];
      map<int,int> mp;
      for(int i=0;i<n;i++)
      {
          cin>>arr[i];
          mp[arr[i]]++;

      }
     // cout<<mp.size()<<endl;
      int fr[mp.size()];
      int c=0;
      map<int,int> ::iterator it= mp.begin();
      while(it!=mp.end())
      {
       //   cout<<it->second<<"   ";
          fr[c]= it->second ;
          it++;
          c++;
      }
     sort(fr,fr+mp.size());
      int sum=0;
     for(int i=0;i<(int)mp.size()-k;i++)
        sum+=fr[i];

     cout<<sum;








        return 0;
    }
