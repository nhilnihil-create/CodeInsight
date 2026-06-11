#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;
//全探索
// int main()
// {

//     int D, G;

//     cin >> D >> G;

//     vector<int> P(D);
//     vector<int> C(D);

//     int sum = 0;
//     vector<int> sum_st(D);
//     vector<int> sum_ed(D);

//     for (int i = 0; i < D; i++)
//     {

//         cin >> P[i] >> C[i];

//         sum_st[i] = sum;

//         sum = sum + P[i];

//         sum_ed[i] = sum;
//     }

//     int score = 0;

//     int bit = 0;

//     int ans = sum;

//     for (ll bit = 0; bit < (1 << sum); bit++)
//     {

//         int score = 0;
//         int trys = 0;
//         for (int i = 0; i < D; i++)
//         {

//             bool all_flag = 1;

//                 int mini_try =0;
//             for (int k = sum_st[i]; k < sum_ed[i]; k++)
//             {

//                 if (bit & (1 << k))
//                 {

//                     mini_try++;

//                     trys++;
//                     score += (i+1)*100;
//                 }
//                 else
//                 {

//                     all_flag = 0;
//                 }
//             }

//             if(i==0){

//               cout << bit << endl;

//             }

//             if (all_flag == 1)
//             {

//                 if(P[i]!=1){
//                     cout << P[i] << endl;

//                 }

//                 score += C[i];
//             }
//         }

//         if (G <= score)
//         {

//             ans = min(trys, ans);
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

int main()
{

    int D, G;

    cin >> D >> G;

    vector<int> P(D);
    vector<int> C(D);

    int sum = 0;

    for (int i = 0; i < D; i++)
    {

        cin >> P[i] >> C[i];

        sum += P[i];
    }

    int ans = sum;

    for (int bit; bit < (1 << D); bit++)
    {

        vector<int> use(0);
        int unuse = 0;
        for (int i = 0; i < D; i++)
        {

            if ((1 << i) & bit)
            {

                use.push_back(i);
            }
            else
            {

                unuse = max(i, unuse);
            }
        }

        int score = 0;

        int trys = 0;

        for (int k :use)
        {

            score += C[k];

            score += P[k] * (k + 1) * 100;
            trys += P[k];
        }

        if (score >= G)
        {

            ans = min(trys, ans);
        }

        else
        {

            bool kasu_flag = 1;

            for (int j = 0; j < P[unuse] - 1; j++)
            {

                score += 100 * (unuse + 1);
                trys++;

                if (score >= G)
                {

                    kasu_flag = 0;
                    ans = min(trys, ans);

                    break;
                }
            }
        }
    }


cout << ans << endl;

return 0;
}