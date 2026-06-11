    #include<iostream>
    #include<vector>
    #include<math.h>
    #include<bits/stdc++.h>
    #include<sstream>
     
    using namespace std;
     
    int main()
    {
        int s, x, i = 2;
        vector<int> nums;
        vector<int>::iterator it;
        //bool yes = true;

        cin >> s;
        
        nums.push_back(s);

        while(true)
        {
            if(s%2==0)
            {
                x = s/2;
            }

            else
            {
                x = s*3 + 1;
            }
            

            it = find(nums.begin(),nums.end(),x);

            if(it == nums.end())
            {
                nums.push_back(x);
                i++;
                s = x;
            }

            else
            {
                cout << i;
                exit(0);
            }
            
        }
    } 